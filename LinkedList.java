import java.io.*;

class Node{
    public int value;
    public Node next;
    Node(int value){
        this.value = value;
        this.next = null;
    }
}

class LList{
    private Node head = null;
    private int length = 0;

    public void printList(){
        if(this.head==null){
            System.out.println("Linked list is empty!\n");
            return;
        }
        Node tmp = this.head;
        while(tmp!=null){
            System.out.print(tmp.value+", ");
            tmp=tmp.next;
        }
        System.out.println();
    }

    public void insert(int value){
        if(this.head==null){
            this.head= new Node(value);
            this.length+=1;
            return;
        }
        Node tmp = this.head;
        while(tmp.next!=null){
            tmp=tmp.next;
        }
        tmp.next = new Node(value);
        this.length+=1;
    }

    public boolean delete(int value){
        if(this.head==null){
            return false;
        }
        Node tmp;
        tmp=this.head;
        if(this.head.value==value){
            
            this.head=tmp.next;
            tmp=null;
            this.length=-1;
            return true;
        }
        while(tmp.next!=null){
            if(tmp.next.value==value){

            }
            tmp = tmp.next;
        }
        return false;
    }

    public static void main(String[] args){
        LList testList = new LList();
        for(int i=0;i<10;i++){
            testList.insert(i);
        }
        testList.printList();
    }
}

