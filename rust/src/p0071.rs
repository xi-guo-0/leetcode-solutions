struct Solution;

impl Solution {
    pub fn simplify_path(path: String) -> String {
        let mut simplified_path = vec![];
        for dir in path.split('/') {
            match dir {
                "" | "." => continue,
                ".." => {
                    simplified_path.pop();
                }
                _ => {
                    simplified_path.push(dir);
                }
            }
        }
        "/".to_owned() + &simplified_path.join("/")
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_simplify_path() {
        assert_eq!(Solution::simplify_path(String::from("/home/")), "/home");
        assert_eq!(
            Solution::simplify_path(String::from("/home//foo/")),
            "/home/foo"
        );
        assert_eq!(
            Solution::simplify_path(String::from("/home/user/Documents/../Pictures")),
            "/home/user/Pictures"
        );
        assert_eq!(Solution::simplify_path(String::from("/../")), "/");
        assert_eq!(
            Solution::simplify_path(String::from("/.../a/../b/c/../d/./")),
            "/.../b/d"
        );
    }
}
