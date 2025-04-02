struct Solution;

type SudokuUnit = [usize; 9];

fn is_valid_unit(u: SudokuUnit) -> bool {
    u.into_iter().all(|cnt| cnt <= 1)
}

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        for r in 0..9 {
            let mut a: SudokuUnit = Default::default();
            for c in 0..9 {
                let ch = board[r][c];
                if '1' <= ch && ch <= '9' {
                    let num = board[r][c] as usize - '1' as usize;
                    a[num] += 1;
                }
            }
            if !is_valid_unit(a) {
                return false;
            }
        }
        for c in 0..9 {
            let mut a: SudokuUnit = Default::default();
            for r in 0..9 {
                let ch = board[r][c];
                if '1' <= ch && ch <= '9' {
                    let num = board[r][c] as usize - '1' as usize;
                    a[num] += 1;
                }
            }

            if !is_valid_unit(a) {
                return false;
            }
        }
        for tlr in (0..9).step_by(3) {
            for tlc in (0..9).step_by(3) {
                let mut a: SudokuUnit = Default::default();
                for i in 0..3 {
                    for j in 0..3 {
                        let ch = board[tlr + i][tlc + j];
                        if '1' <= ch && ch <= '9' {
                            let num = board[tlr + i][tlc + j] as usize - '1' as usize;
                            a[num] += 1;
                        }
                    }
                }

                if !is_valid_unit(a) {
                    return false;
                }
            }
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_is_valid_sudoku() {
        assert_eq!(
            Solution::is_valid_sudoku(vec![
                vec!['5', '3', '.', '.', '7', '.', '.', '.', '.'],
                vec!['6', '.', '.', '1', '9', '5', '.', '.', '.'],
                vec!['.', '9', '8', '.', '.', '.', '.', '6', '.'],
                vec!['8', '.', '.', '.', '6', '.', '.', '.', '3'],
                vec!['4', '.', '.', '8', '.', '3', '.', '.', '1'],
                vec!['7', '.', '.', '.', '2', '.', '.', '.', '6'],
                vec!['.', '6', '.', '.', '.', '.', '2', '8', '.'],
                vec!['.', '.', '.', '4', '1', '9', '.', '.', '5'],
                vec!['.', '.', '.', '.', '8', '.', '.', '7', '9']
            ]),
            true
        );
        assert_eq!(
            Solution::is_valid_sudoku(vec![
                vec!['8', '3', '.', '.', '7', '.', '.', '.', '.'],
                vec!['6', '.', '.', '1', '9', '5', '.', '.', '.'],
                vec!['.', '9', '8', '.', '.', '.', '.', '6', '.'],
                vec!['8', '.', '.', '.', '6', '.', '.', '.', '3'],
                vec!['4', '.', '.', '8', '.', '3', '.', '.', '1'],
                vec!['7', '.', '.', '.', '2', '.', '.', '.', '6'],
                vec!['.', '6', '.', '.', '.', '.', '2', '8', '.'],
                vec!['.', '.', '.', '4', '1', '9', '.', '.', '5'],
                vec!['.', '.', '.', '.', '8', '.', '.', '7', '9']
            ]),
            false
        );
    }
}
