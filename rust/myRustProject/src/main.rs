fn main() {
    println!("Hello, world!");
    init();
    loop{
        let num = menu_print();
        if num == 1{
            println!("play game....");
        }
        else if num == 2{
            println!("option..??????");
        }
        else if num == 3{
            println!("Game quit... bye...");
            break;
        }
    }
}

fn init() {
    println!("Start Game..?");
}

fn menu_print()->i32{
    println!("1. Game start");
    println!("2. Option?");
    println!("3. Exit...");
    3
}

