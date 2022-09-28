// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        var diffMap = mutableMapOf<Int, Int>()
        nums.forEachIndexed { index, value ->
            diffMap[value]?.let {
                return intArrayOf(it, index)
            }
            diffMap[target - value] = index
        }
        return intArrayOf()
    }
}