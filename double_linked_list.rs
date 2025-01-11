#![allow(non_snake_case)]

pub struct Node<T>{
	pub value: Option<T>,
	pub next: Option<Box<Node<T>>>
}

impl<T> Node<T> {
	pub fn new() -> Node<T> {
		Node {
			value: None,
			next: None,
		}
	}
}

pub struct List<T> {
	pub head: Option<Node<T>>,
	pub tail: Option<Node<T>>
}

impl<T> List<T> {
    pub fn new() -> List<T> {
        List {
            head: None,
            tail: None,
        }
    }
}

pub fn printNode<T:std::fmt::Display>(node: Node<T>) {
	match node.value {
		None => println!("Node: {}", "NULL"),
		Some(value) => println!("Node: {}", value),
	}
}

fn main() {
	let _list: List<i32> = List::<i32>::new();
	let node: Node<i32> = Node::<i32>::new();
    printNode(node);
}
