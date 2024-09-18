class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        res = 0
        allowed_bitmask = 0
        for ch in allowed:
            bit = ord(ch) - ord('a')
            allowed_bitmask |= (1<<bit)
        
        for word in words:
            word_mask = 0
            for ch in word:
                bit = ord(ch) - ord('a')
                word_mask |= (1<<bit)
            if (word_mask & allowed_bitmask) == word_mask:
                res += 1
            
        return res
