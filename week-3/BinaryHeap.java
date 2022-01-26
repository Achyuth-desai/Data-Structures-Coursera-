import java.util.*;
public class BinaryHeap {
	static int size=0, maxSize = 20;
	static int[] array = new int[20];
	BinaryHeap() {
		array[0] = -1;
	}
	
	public static void Insert(int value) {
		if(size == maxSize) {
			System.out.println("No space in heap");
			return;
		}
		array[++size] = value;
		shiftup(size);
	}
	public static int GetMax() {
		if(size == 0)
			return -1;
		return array[1];
	}
	public static int ExtractMax() {
		int temp = GetMax();
		array[1] = array[size];
		size = size - 1;
		shiftdown(1);
		return temp;
	}
	public static void Remove(int index) {
		if(index > size) {
			System.out.println("Index out of bounds");
			return;
		}
		array[index] = 10000;
		shiftup(index);
		ExtractMax();
	}
	public static void shiftdown(int index) {
		int maxIndex = index, temp;
		int left = LeftChild(index);
		if(left <= size && array[left] > array[maxIndex])
			maxIndex = left;
		int right  = RightChild(index);
		if(right <= size && array[right] > array[maxIndex])
			maxIndex = right;
		if(maxIndex != index) {
			temp = array[maxIndex];
			array[maxIndex] = array[index];
			array[index] = temp;
			shiftdown(maxIndex);
		}
	}
	public static void shiftup(int index) {
		int temp;
		while(index > 1 && array[Parent(index)] < array[index]) {
			temp = array[Parent(index)];
			array[Parent(index)] = array[index];
			array[index] = temp;
			index = Parent(index);
		}
	}
	public static void display() {
		System.out.print("Heap : ");
		for(int i=1;i<=size;i++) {
			System.out.print(array[i] + "  ");
		}
		System.out.println();
		System.out.println();
	}
	
	
	public static int Parent(int index) {
		return index/2;
	}
	public static int LeftChild(int index) {
		return 2*index;
	}
	public static int RightChild(int index) {
		return 2*index + 1;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the size of the heap : ");
		maxSize = in.nextInt();
		for(int i=1;i<=maxSize;i++) {
			int temp = in.nextInt();
			Insert(temp);
		}
		while(true) {
			System.out.println("Enter operation to perform : ");
			System.out.println("1.Get maximum value from the heap");
			System.out.println("2.Insert and element into the heap");
			System.out.println("3.Extract the maximum value from the heap");
			System.out.println("4.Change priority of node in heap");
			System.out.println("5.Remove a node from the heap");
			System.out.println("6.Exit");
			System.out.print("Enter Choice : ");
			int choice = in.nextInt();
			switch(choice) {
			case 1:
				System.out.println("Maximum value : " + GetMax());
				break;
			case 2:
				System.out.print("Enter value");
				int value = in.nextInt();
				Insert(value);
				break;
			case 3:
				System.out.println("Maximum value : " + ExtractMax());
				break;
			case 4:
				System.out.print("Enter the value of the index : ");
				int index = in.nextInt();
				System.out.print("Enter new priority :");
				int p = in.nextInt();
				ChangePriority(index, p);
				break;
			case 5:
				System.out.print("Enter the value of the index : ");
				int index1 = in.nextInt();
				Remove(index1);
				break;
			case 6:
				System.exit(0);
			default:
				System.out.println("Invalid Choice");
				break;
			}
			display();
		}	
	}
	private static void ChangePriority(int index, int priority) {
		int oldp = array[index];
		array[index] = priority;
		if(priority > oldp)
			shiftup(index);
		else
			shiftdown(index);
		
	}
}
