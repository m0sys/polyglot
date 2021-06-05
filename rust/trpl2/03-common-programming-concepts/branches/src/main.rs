fn main() {
    println!("Hello, world!");

    let number = 3;
    if number < 5 {
        println!("true cond");
    } else {
        println!("false cond");
    }

    // Ternary operation ish.
    let cond = true;
    let num = if cond { 5 } else { 6 };

    println!("The value of num is {}", num);
}
