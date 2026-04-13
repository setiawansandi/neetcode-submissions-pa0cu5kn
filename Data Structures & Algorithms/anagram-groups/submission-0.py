class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dict_of_anagrams = defaultdict(list)
        
        for _str in strs:
            dict_of_anagrams[''.join(sorted(_str))].append(_str)

        values_as_lists = list(dict_of_anagrams.values())
        return(values_as_lists)
