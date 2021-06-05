fn main() {
    println!("Hello, world!");

    another_func(42, 192.8);
    let x = five();
    println!("The value of x is: {}", x);
    let x = plus_one(10);
    println!("The value of x is: {}", x);
}

fn another_func(x: i32, y: f32) {
    println!("Another function. My values are {} and {}", x, y);
}

fn five() -> i32 {
    5
}

fn plus_one(x: i32) -> i32 {
    x + 1
}
