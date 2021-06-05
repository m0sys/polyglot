fn main() {
    println!("Hello, world!");

    let mut counter = 0;
    let res = loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    };

    println!("The result is {}", res);

    let mut num = 3;
    while num != 0 {
        println!("{}!", num);
        num -= 1;
    }
    println!("LIFT OFF!!!");

    let a = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192];
    let mut index = 0;
    while index < a.len() {
        println!("the value at index {} is {}", index, a[index]);
        index += 1;
    }

    for power in a.iter() {
        println!("the power of 2^n = {}", power);
    }

    for num in (1..4).rev() {
        println!("{}!", num);
    }
    println!("LIFT OFF!!!");
    println!("fib(10) = {}", fib(10));
}

fn fib(n: i32) -> i32 {
    if n == 0 {
        return 0;
    }

    if n == 1 {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}
