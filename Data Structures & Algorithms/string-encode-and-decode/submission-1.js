class Solution {
    /**
     * @param {string[]} strs
     * @returns {string}
     */
    encode(strs) {
        let encoded = "";
        for (const str of strs) {
            encoded += str + "/@$"
        }
        return encoded;
    }

    /**
     * @param {string} str
     * @returns {string[]}
     */
    decode(str) {
        let strs = [];
        let word = "";
        let seperator = "/@$";
        let count = 0;

        for(let i = 0; i < str.length; i++) {
            word += str[i];

            if(str[i] === seperator[count]) {
                count++;
                if(count === seperator.length) {
                    strs.push(word.slice(0, -seperator.length));
                    word = "";
                    count = 0;
                }
            }
            else if(str[i] !== seperator[0]) {
                count = 0;
            }
        }
        return strs;
    }
}
