#[macro_export]
macro_rules! tree {
    () => {
        None
    };
    ($($x:tt),*) => {
        {
            let vec: Vec<Option<i32>> = vec![$(
                match stringify!($x) {
                    "null" => None,
                    num => Some(num.parse().unwrap()),
                }
            ),*];
            leetcode_input_to_tree(&vec)
        }
    };
}
