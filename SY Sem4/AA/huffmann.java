import java.util.*;
import java.io.*;

// node
class NodeHuffmann {

    int data;
    char c;

    NodeHuffmann left;
    NodeHuffmann right;
}

class compareData implements Comparator<NodeHuffmann> {
    public int compare(NodeHuffmann x, NodeHuffmann y) {

        return x.data - y.data;
    }
}

class Huffman {

    // recursive function to print the huffmann code
    public static void printCodedHuffman(NodeHuffmann root, String s) {

        // base case - leaf node
        if (root.left == null && root.right == null && Character.isLetter(root.c)) {
            System.out.println(root.c + ":" + s);
            return;
        }

        printCodedHuffman(root.left, s + "0");
        printCodedHuffman(root.right, s + "1");
    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        System.out.println("Enter number of characters : ");
        int n = s.nextInt();

        char[] charArray = new char[n];
        int[] charfreq = new int[n];

        PriorityQueue<NodeHuffmann> q = new PriorityQueue<NodeHuffmann>(n, new compareData());

        for (int i = 0; i < n; i++) {

            // input
            System.out.print("Enter character : ");
            charArray[i] = s.next().charAt(0);
            System.out.print("Enter frequency : ");
            charfreq[i] = s.nextInt();

            NodeHuffmann node = new NodeHuffmann();
            node.c = charArray[i];
            node.data = charfreq[i];
            node.left = null;
            node.right = null;
            q.add(node);
        }

        NodeHuffmann root = null;
        while (q.size() > 1) {

            NodeHuffmann x = q.peek();
            q.poll();

            NodeHuffmann y = q.peek();
            q.poll();

            NodeHuffmann f = new NodeHuffmann();
            f.data = x.data + y.data;
            f.c = '-';
            f.left = x;
            f.right = y;
            root = f;

            q.add(f);
        }

        printCodedHuffman(root, "");
    }
}
