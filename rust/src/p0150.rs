impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut stack: Vec<i32> = Vec::new();

        fn is_operator(s: &str) -> bool {
            s == "+" || s == "-" || s == "*" || s == "/"
        }

        for token in tokens {
            if is_operator(&token) {
                let ele2 = stack.pop().unwrap();
                let ele1 = stack.pop().unwrap();
                let result = match token.as_str() {
                    "+" => ele1 + ele2,
                    "-" => ele1 - ele2,
                    "*" => ele1 * ele2,
                    "/" => ele1 / ele2,
                    _ => 0,
                };
                stack.push(result);
            } else {
                let num: i32 = token.parse().unwrap();
                stack.push(num);
            }
        }

        stack.pop().unwrap()
    }
}
