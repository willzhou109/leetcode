class Solution(object):
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        # sort 2 lists based on the position list
        pairs = zip(position, speed)
        sorted_pairs = sorted(pairs, reverse = True)
        sorted_position, sorted_speed = zip(*sorted_pairs)
        stack = []
        for i in range(len(sorted_position)):
            time = float(target - sorted_position[i]) / sorted_speed[i]
            if i == 0:
                stack.append(time)
                continue
            if time > stack[-1]: # time of current car vs current fleet's lead (slowest) car
                stack.append(time)
        print(stack)
        return len(stack)



        