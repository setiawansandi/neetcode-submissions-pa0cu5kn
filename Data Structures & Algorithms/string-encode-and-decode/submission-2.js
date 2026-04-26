class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
        let sizes = [];
        let sizestr = ""
        let encoded = "";
        for(const str of strs) {
            sizes.push(str.length);
            encoded += str;
        }
        for(const size of sizes) {
            sizestr += size + ",";
        }

        return encoded = sizestr + "#" + encoded;
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
        if (str.length === 0) return [""];

        let sliceIdx = 0;
        let size = "";
        let sizes = [];
        for(let i = 0; i < str.length; i++) {
            size += str[i];
            if(str[i] === ",") {
                sizes.push(parseInt(size, 10));
                size = "";
            }
            if(str[i] === "#") {
                sliceIdx = i+1;
                break;
            }
        }

        let decoded = [];
        for(let sz of sizes) {
            decoded.push(str.slice(sliceIdx, sliceIdx + sz));
            sliceIdx += sz;
        }

        return decoded;
    }
}
