import java.io.*;
import java.util.*;

class TreeNode{
    int value;
    TreeNode left;
    TreeNode right;
    TreeNode(int value){
        this.value = value;
    }
}

class BST{
    private TreeNode root = null;
    private LinkedList<Integer> contentBuf = new LinkedList<Integer>();

    public void insert(int value){
        if(this.root == null){
            this.root = new TreeNode(value);
            return;
        }
        TreeNode tmp = this.root;
        while(true){
            if(value<tmp.value){
                if(tmp.left==null){
                    tmp.left = new TreeNode(value);
                    return;
                }
                tmp = tmp.left;
            }else if(value>tmp.value){
                if(tmp.right==null){
                    tmp.right = new TreeNode(value);
                }
                tmp = tmp.right;
            }else{
                return;
            }
        }
    }

    public boolean ifExist(int value){
        TreeNode tmp = this.root;
        while(tmp!=null){
            if(value<tmp.value){
                tmp = tmp.left;
            }else if(value>tmp.value){
                tmp = tmp.right;
            }else{
                return true;
            }
        }
        return false;
    }

    public void printTree(){
        if(this.contentBuf.size()==0){
            System.out.println("Not traversed yet");
            return;
        }
        Iterator<Integer> ite = this.contentBuf.listIterator();
        while(ite.hasNext()){
            System.out.print(ite.next()+", ");
        }
        System.out.println();
    }

    public void levelOrderTraverse(){
        this.contentBuf.clear();
        LinkedList<TreeNode> queue = new LinkedList<TreeNode> ();
        TreeNode tmp = this.root;
        queue.add(tmp);
        while(queue.size()>0){
            TreeNode n = queue.poll();
            this.contentBuf.add(n.value);
            // System.out.print(n.value+", ");
            if(n.left!=null)
                queue.add(n.left);
            if(n.right!=null)
                queue.add(n.right);
        }
    }

    public void InOrderTraverse(){
        TreeNode tmp = this.root;
        InOrderHelper(tmp);
        // System.out.println("");
    }

    private void InOrderHelper(TreeNode n){
        if(n!=null){
            InOrderHelper(n.left);
            this.contentBuf.add(n.value);
            // System.out.print(n.value+", ");
            InOrderHelper(n.right);
        }
    }

    public void rebalance(){
        this.contentBuf.clear();
        InOrderTraverse();
        int size = this.contentBuf.size();
        int [] bufArray = new int[size];
        Iterator<Integer> i = this.contentBuf.listIterator();
        int index = 0;
        while(i.hasNext()){
            bufArray[index]=i.next();
            index+=1;
        }
        this.root=null;
        balanceBuild(bufArray, 0, bufArray.length-1);
    }

    private void balanceBuild(int[] values, int start, int end){
        if(end<start){
            return;
        }
        int mid = (end+start)/2;
        insert(values[mid]);
        balanceBuild(values, start, mid-1);
        balanceBuild(values, mid+1, end);
    }

    public static void main(String args[]){
        BST testTree = new BST();
        for(int i=0;i<10;i++){
            testTree.insert(i);
        }
        testTree.rebalance();
        testTree.printTree();
        testTree.levelOrderTraverse();
        testTree.printTree();
    }

}