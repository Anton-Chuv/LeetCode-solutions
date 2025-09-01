class Solution {
    fun isValidSudoku(board: Array<CharArray>): Boolean {
        for (i in 0..8) {
            val row = HashSet<Char>()
            val col = HashSet<Char>()
            val box = HashSet<Char>()
            for (j in 0..8) {
                val rowChar = board[i][j]
                val colChar = board[j][i]
                val boxChar = board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]
                if (rowChar != '.' && !row.add(rowChar)) return false
                if (colChar != '.' && !col.add(colChar)) return false
                if (boxChar != '.' && !box.add(boxChar)) return false
            }
        }
        return true
    }
}
