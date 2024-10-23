class Solution:
    def relocateMarbles(self, nums: List[int], moveFrom: List[int], moveTo: List[int]) -> List[int]:
        move = dict()
        for num in nums:
            if not num in move.keys():
                move[num] = list()
                move[num].append(num)
        for num in moveFrom:
            if not num in move.keys():
                move[num] = list()                
                move[num].append(num)
        for idx in range(len(moveFrom)):
            if moveFrom[idx] == moveTo[idx]:
                continue
            if not moveTo[idx] in move.keys():
                move[moveTo[idx]] = list()
            move[moveTo[idx]].extend(move[moveFrom[idx]])
            move[moveFrom[idx]].clear()
        
        rev_move = dict()
        for key, values in move.items():
            for value in values:
                rev_move[value] = key
        res = []
        S = set()
        for num in nums:
            if num in rev_move.keys():
                S.add(rev_move[num])
            else:
                S.add(num)
        
        for num in S:
            res.append(num)

        res.sort()
        
        return res
