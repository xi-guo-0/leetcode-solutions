impl Solution {
    pub fn count_students(mut students: Vec<i32>, mut sandwiches: Vec<i32>) -> i32 {
        let mut students_visited = 0;
        while sandwiches.len() != 0 && students_visited != students.len() {
            let cur_student = students.remove(0);
            if cur_student == sandwiches[0] {
                sandwiches.remove(0);
                students_visited = 0;
            } else {
                students.push(cur_student);
                students_visited += 1;
            }
        }
        students.len() as i32
    }
}
