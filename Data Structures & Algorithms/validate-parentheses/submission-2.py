class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 1: return False

        bracket = {"}":"{", "]":"[", ")":"("}
        stk = []

        for c in s:
            if c not in bracket.keys() or not stk:
                stk.append(c)
            else:
                if bracket[c] == stk[-1]:
                    stk.pop()
                else:
                    return False
        
        return len(stk) == 0

