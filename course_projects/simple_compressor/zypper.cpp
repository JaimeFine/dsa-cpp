#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstdint>
#include <cstring>

using namespace std;

template<typename T>
struct HuffNode {
    T sym;                 // valid for leaves
    uint64_t freq;
    HuffNode* left;
    HuffNode* right;
    HuffNode(T s, uint64_t f) : sym(s), freq(f), left(NULL), right(NULL) {}
    HuffNode(uint64_t f, HuffNode* l, HuffNode* r) : sym(0), freq(f), left(l), right(r) {}
    bool isLeaf() const { return left == NULL && right == NULL; }
};

template<typename T>
struct NodeCmp {
    bool operator()(HuffNode<T>* a, HuffNode<T>* b) {
        return a->freq > b->freq; // min-heap
    }
};

template<typename T>
class Huffman {
public:
    Huffman() : root(NULL) {}
    ~Huffman() { freeTree(root); }

    // Build tree from frequency table
    void build(const map<T, uint64_t>& freq) {
        priority_queue<HuffNode<T>*, vector<HuffNode<T>*>, NodeCmp<T>> pq;
        for (auto it : freq) {
            pq.push(new HuffNode<T>(it.first, it.second));
        }

        if (pq.empty()) { root = NULL; return; }
        if (pq.size() == 1) {
            // Single-symbol edge case: create a dummy root so code becomes "0"
            HuffNode<T>* only = pq.top(); pq.pop();
            root = new HuffNode<T>(only->freq, only, NULL);
            return;
        }

        while (pq.size() > 1) {
            HuffNode<T>* a = pq.top(); pq.pop();
            HuffNode<T>* b = pq.top(); pq.pop();
            HuffNode<T>* parent = new HuffNode<T>(a->freq + b->freq, a, b);
            pq.push(parent);
        }
        root = pq.top();
    }

    // Generate codes: '0' for left, '1' for right
    void generateCodes(map<T, string>& codes) const {
        codes.clear();
        string path = "";
        dfs(root, path, codes);
    }

    // Decode a string of '0'/'1' into symbols
    // Stops when outputCount symbols are produced
    void decodeBitsString(const string& bits, vector<T>& out, uint64_t outputCount) const {
        HuffNode<T>* cur = root;
        for (size_t i = 0; i < bits.size() && out.size() < outputCount; ++i) {
            if (!cur) break;
            if (cur->isLeaf()) {
                out.push_back(cur->sym);
                cur = root;
            }
            char bit = bits[i];
            if (bit == '0') cur = cur->left;
            else cur = cur->right;
        }
        // Final leaf emission after loop
        if (cur && cur->isLeaf() && out.size() < outputCount) {
            out.push_back(cur->sym);
        }
    }

    HuffNode<T>* getRoot() const { return root; }

private:
    HuffNode<T>* root;

    void dfs(HuffNode<T>* node, string& path, map<T, string>& codes) const {
        if (!node) return;
        if (node->isLeaf()) {
            if (path.empty()) codes[node->sym] = "0"; // single-symbol case
            else codes[node->sym] = path;
            return;
        }
        if (node->left) {
            path.push_back('0'); dfs(node->left, path, codes); path.pop_back();
        }
        if (node->right) {
            path.push_back('1'); dfs(node->right, path, codes); path.pop_back();
        }
    }

    void freeTree(HuffNode<T>* n) {
        if (!n) return;
        freeTree(n->left);
        freeTree(n->right);
        delete n;
    }
};

// Pack a '0'/'1' string into bytes (MSB-first). Return vector<uint8_t>.
static vector<uint8_t> packBitsString(const string& bits) {
    vector<uint8_t> out;
    uint8_t cur = 0;
    int pos = 0; // 0..7
    for (char c : bits) {
        int b = (c == '1') ? 1 : 0;
        cur |= (uint8_t(b) << (7 - pos));
        pos++;
        if (pos == 8) {
            out.push_back(cur);
            cur = 0;
            pos = 0;
        }
    }
    if (pos != 0) out.push_back(cur);
    return out;
}

// Unpack bytes into a '0'/'1' string (MSB-first). If bitCount >= 0, stop after that many bits.
static string unpackBitsString(const vector<uint8_t>& bytes, int64_t bitCount) {
    string bits;
    int64_t produced = 0;
    for (size_t i = 0; i < bytes.size(); ++i) {
        for (int pos = 0; pos < 8; ++pos) {
            if (bitCount >= 0 && produced >= bitCount) return bits;
            int b = (bytes[i] >> (7 - pos)) & 1;
            bits.push_back(b ? '1' : '0');
            produced++;
        }
    }
    return bits;
}

static void writeHeader(ofstream& out,
                        uint64_t originalSize,
                        uint64_t bitCount,
                        const map<uint8_t, uint64_t>& freq) {
    const char magic[4] = {'H','F','N','1'};
    out.write(magic, 4);
    out.write(reinterpret_cast<const char*>(&originalSize), sizeof(originalSize));
    out.write(reinterpret_cast<const char*>(&bitCount), sizeof(bitCount));
    // Write 256 frequencies in fixed order
    for (int i = 0; i < 256; ++i) {
        uint64_t f = 0;
        auto it = freq.find(static_cast<uint8_t>(i));
        if (it != freq.end()) f = it->second;
        out.write(reinterpret_cast<const char*>(&f), sizeof(uint64_t));
    }
}

static bool readHeader(ifstream& in,
                       uint64_t& originalSize,
                       uint64_t& bitCount,
                       map<uint8_t, uint64_t>& freq) {
    char magic[4];
    if (!in.read(magic, 4)) return false;
    if (memcmp(magic, "HFN1", 4) != 0) return false;
    if (!in.read(reinterpret_cast<char*>(&originalSize), sizeof(originalSize))) return false;
    if (!in.read(reinterpret_cast<char*>(&bitCount), sizeof(bitCount))) return false;
    freq.clear();
    for (int i = 0; i < 256; ++i) {
        uint64_t f = 0;
        if (!in.read(reinterpret_cast<char*>(&f), sizeof(uint64_t))) return false;
        if (f > 0) freq[(uint8_t)i] = f;
    }
    return true;
}

static bool compressFile(const string& inPath, const string& outPath) {
    ifstream in(inPath, ios::binary);
    if (!in) { cerr << "Cannot open input\n"; return false; }

    // Read all bytes
    vector<uint8_t> data;
    in.seekg(0, ios::end);
    streampos endPos = in.tellg();
    in.seekg(0, ios::beg);
    size_t sz = (size_t)endPos;
    data.resize(sz);
    if (sz > 0 && !in.read(reinterpret_cast<char*>(data.data()), sz)) {
        cerr << "Read error\n"; return false;
    }

    // Frequency map
    map<uint8_t, uint64_t> freq;
    for (size_t i = 0; i < data.size(); ++i) {
        freq[data[i]]++;
    }

    // Build Huffman
    Huffman<uint8_t> huff;
    huff.build(freq);

    // Codes as '0'/'1' strings
    map<uint8_t, string> codes;
    huff.generateCodes(codes);

    // Encode: concatenate codes for each byte
    string bitString;
    bitString.reserve(data.size() * 2); // rough reserve to reduce realloc
    for (size_t i = 0; i < data.size(); ++i) {
        bitString += codes[data[i]];
    }

    // Pack bits into bytes
    vector<uint8_t> payload = packBitsString(bitString);
    uint64_t bitCount = (uint64_t)bitString.size();

    // Write output
    ofstream out(outPath, ios::binary);
    if (!out) { cerr << "Cannot open output\n"; return false; }
    writeHeader(out, (uint64_t)data.size(), bitCount, freq);
    if (!payload.empty()) {
        out.write(reinterpret_cast<const char*>(payload.data()), (streamsize)payload.size());
    }
    return true;
}

static bool decompressFile(const string& inPath, const string& outPath) {
    ifstream in(inPath, ios::binary);
    if (!in) { cerr << "Cannot open compressed file\n"; return false; }

    uint64_t originalSize = 0, bitCount = 0;
    map<uint8_t, uint64_t> freq;
    if (!readHeader(in, originalSize, bitCount, freq)) {
        cerr << "Invalid header\n"; return false;
    }

    // Read payload
    vector<uint8_t> payload;
    in.seekg(0, ios::end);
    streampos endPos = in.tellg();
    streampos curPos = in.tellg();
    // after header, in's position is at payload start
    streampos payloadStart = curPos; // actually curPos equals endPos due to seek
    // fix: set to current position before seek end
    in.clear();
    in.seekg(4 + 8 + 8 + 256 * 8, ios::beg); // magic + originalSize + bitCount + freq table
    payloadStart = in.tellg();

    size_t payloadBytes = (size_t)(endPos - payloadStart);
    if (payloadBytes > 0) {
        payload.resize(payloadBytes);
        in.read(reinterpret_cast<char*>(payload.data()), payloadBytes);
    }

    // Rebuild Huffman
    Huffman<uint8_t> huff;
    huff.build(freq);

    // Unpack bits to '0'/'1' string (limit by bitCount)
    string bitString = unpackBitsString(payload, (int64_t)bitCount);

    // Decode to bytes
    vector<uint8_t> outBytes;
    outBytes.reserve((size_t)originalSize);
    huff.decodeBitsString(bitString, outBytes, originalSize);

    // Write output
    ofstream out(outPath, ios::binary);
    if (!out) { cerr << "Cannot open output file\n"; return false; }
    if (!outBytes.empty()) {
        out.write(reinterpret_cast<const char*>(outBytes.data()), (streamsize)outBytes.size());
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        cerr << "Usage:\n"
             << "  ./zypper -c <input> <output.huf>\n"
             << "  ./zypper -d <input.huf> <output>\n";
        return 1;
    }

    string mode = argv[1];
    string inPath = argv[2];
    string outPath = argv[3];

    if (mode == "-c") {
        if (!compressFile(inPath, outPath)) return 2;
        cout << "Compressed: " << inPath << " -> " << outPath << "\n";
    } else if (mode == "-d") {
        if (!decompressFile(inPath, outPath)) return 3;
        cout << "Decompressed: " << inPath << " -> " << outPath << "\n";
    } else {
        cerr << "Unknown mode: " << mode << "\n";
        return 4;
    }
    return 0;
}
