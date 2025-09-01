class Solution {
    fun maxAverageRatio(classes: Array<IntArray>, extraStudents: Int): Double {
        val n = classes.size
        var maxAvgRatio = 0.0
        var extraRatioClasses: MutableMap<Double, IntArray> = mutableMapOf(1.0 to intArrayOf(0, 0))

        for (i in 0 until n) {
            val extraRatio =
                (classes[i][0].toDouble() + 1) / (classes[i][1] + 1) - classes[i][0].toDouble() / classes[i][1]
            extraRatioClasses += Pair(extraRatio, classes[i])
        }
        extraRatioClasses = extraRatioClasses.toSortedMap()
        for (i in 0 until extraStudents) {
            val oldRatio = extraRatioClasses.keys.last()
            val newClass = intArrayOf(extraRatioClasses[oldRatio]!![0] + 1, extraRatioClasses[oldRatio]!![1] + 1)
            val newRatio = newClass[0].toDouble() + 1 / newClass[1] + 1
            extraRatioClasses.remove(oldRatio)
            extraRatioClasses += Pair(newRatio, newClass)
            extraRatioClasses = extraRatioClasses.toSortedMap()

        }
        for (v in extraRatioClasses.values) {
            maxAvgRatio += v[0].toDouble() / v[1]
        }
        maxAvgRatio /= n

        return maxAvgRatio
    }
}

fun main() {
    val solution = Solution()
    val classes = arrayOf(
        intArrayOf(1, 2),
        intArrayOf(2, 2)
    )

    val extraStudents = 8
    val result = solution.maxAverageRatio(classes, extraStudents)

    println(result)
}

main()