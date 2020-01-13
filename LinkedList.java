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

    public int getLength(){
        return this.length;
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

    public void reverse(){

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
            this.length-=1;
            return true;
        }
        while(tmp.next!=null){
            if(tmp.next.value==value){
                if(tmp.next.next==null){
                    tmp.next = null;
                }else{
                    Node t=tmp.next;
                    tmp.next=tmp.next.next;
                    t=null;
                }
                this.length-=1;
                return true;
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
        if(testList.delete(0)){
            System.out.println("List length "+testList);
        }else{
            System.out.println("Element 0 not in list");
        }
        testList.printList();
        if(testList.delete(9)){
            System.out.println("List length "+testList);
        }else{
            System.out.println("Element 1 not in list");
        }
        testList.printList();
        for(int i=0;i<10;i++){
            if(testList.delete(i)){
                System.out.println("Delete "+i+" from list");
            }else{
                System.out.println("Element "+i+" not in list or list is empty");
            }
        }    
        System.out.println("Length of list is "+testList.getLength());
        testList.printList();
        for(int i=0;i<10;i++){
            testList.insert(i);
        }
        testList.printList();
    }
}

