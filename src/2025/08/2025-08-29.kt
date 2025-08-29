class Solution {
    fun flowerGame(n: Int, m: Int): Long {
        var a1: Long = (m.toLong() + 1) / 2 * (n.toLong() / 2)
        var a2: Long = (n.toLong() + 1) / 2 * (m.toLong() / 2)
        return a1 + a2
    }
}
