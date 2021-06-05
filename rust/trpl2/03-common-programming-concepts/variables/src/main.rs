fn main() {
    // Mutating.
    let mut x = 5;
    println!("The value of x is: {}", x);
    x = 6;
    println!("The value of x is: {}", x);

    // Shadowing.
    let x2 = 5;
    let x2 = x2 + 1;
    let x2 = x2 * 2;
    println!("The value of x is: {}", x2);

    // You can even change type while shadowing a previously defined immutable var.
    let spaces = " ";
    let spaces = spaces.len();
    println!("Number of spaces: {}", spaces);

    // Data types.
    let guess: u64 = "42".parse().expect("Not a number!");
    println!("Guess: {}", guess);

    // Tuples.
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    println!("Tuple: {}, {}, {}", tup.0, tup.1, tup.2);
    // or
    let tup = (500, 6.4, 1);
    println!("Tuple: {}, {}, {}", tup.0, tup.1, tup.2);
    let (_x, y, _z) = tup;
    println!("The value of y is: {}", y);

    //Arrays.
    let a = [1, 2, 3, 4, 5];
    // for  {
    //     println!("i: {} -> a[i] = {}", i, a[i]);
    // }
    let a = [3; 5]; // [3, 3, 3, 3, 3]
}
