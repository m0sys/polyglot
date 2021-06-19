fn main() {
    let mut s = String::from("Hello");
    s.push_str(", World!");
    println!("{}", s);

    let s1 = String::from("hello");
    let s2 = s1; // ownership of the heap mem is transfered to s2
    let s3 = s2.clone();
    println!("{}, world!", s3);

    takes_ownership(s3);
    let x = 5;
    makes_copy(x);
    println!("x: {}", x);

    let s4 = gives_ownership();
    let s5 = String::from("hello");
    let s6 = takes_and_gives_back(s5); // cannot use s5 since ownership is being taken away
    println!("{}", s4);
    println!("{}", s6);

    println!("length of '{}' is {}", s6, calc_length(&s6));
    change(&s6);
    let mut s7 = String::from("we are changing this");
    change2(&mut s7);
    println!("what changed? '{}'", s7);

    let word = first_word(&s);
    println!("word: {}", word);

    // String Slices.
    let s = String::from("hello, world");
    let hello = &s[0..5];
    let world = &s[6..12];
    println!("{}, {}!", hello, world);
}

fn takes_ownership(some_string: String) {
    println!("took ownership of {}", some_string);
}

fn makes_copy(some_int: i32) {
    println!("made copy of {}", some_int);
}

fn gives_ownership() -> String {
    let some_string = String::from("giving ownership");
    some_string
}

fn takes_and_gives_back(a_string: String) -> String {
    a_string + " took the string and added some more stuff"
}

// This is the same idea as C++ references.
// So think of it as a alias for whatever s is pointing to.
fn calc_length(s: &String) -> usize {
    s.len()
}

fn change(some_string: &String) {
    // NOTE: this code doesn't work since references are immutable.
    // some_string.push_str(", world")
    println!("{}", some_string);
}

fn change2(some_string: &mut String) {
    // NOTE: this code doesn't work since references are immutable.
    some_string.push_str(", world")
}

fn first_word(s: &String) -> usize {
    let bytes = s.as_bytes();
    for (i, &_item) in bytes.iter().enumerate() {
        return i;
    }
    s.len()
}
