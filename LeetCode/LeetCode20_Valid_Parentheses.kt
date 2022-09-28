// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
    fun isValid(s: String): Boolean {
        val stack = mutableListOf<Char>()
        
        s.forEach { c: Char -> 
            when (c) {
                '(' -> stack.add(')')
                '[' -> stack.add(']')
                '{' -> stack.add('}')
                else -> {
                    if (stack.isEmpty() || stack.last() != c) {
                        return false
                    } else {
                        stack.removeAt(stack.size - 1)
                    }
                }
            }
        }
        return stack.isEmpty()
    }
}