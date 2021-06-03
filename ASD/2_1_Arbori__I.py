class Tree:

    def __init__(self, root = None):
        self.root = root

    def insert(self,val,current = None):
        new_node = Node(val)

        if current is None:
            current = self.root

            if self.root is None:
                self.root = new_node
                return
        if val <= current.key:
            if current.left is None:
                current.left = new_node
            else:
                self.insert(val, current.left)

        else:
            if current.right is None:
                current.right = new_node
            else:
                self.insert(val, current.right)

    def search(self, val, current = None):
        if current is None:
            if self.root is None:
                return None
            current = self.root
        if current.key == val:
            return current

        if val < current.key:
            if current.left is None:
                return None
            else:
                return self.search(val, current.left)
        else:
            if current.right is None:
                return None
            else:
                return self.search(val, current.right)

    def preorder(self, current = None, is_root = True):
        if current is None and is_root:
            current = self.root;

        if current is None:
            return
        print(current.key, end=" ")
        self.preorder(current.left, False)
        self.preorder(current.right, False)

    def inorder(self, current = None, is_root = True):
        if current is None and is_root:
            current = self.root

        if current is None:
            return

        self.inorder(current.left, False)
        print(current.key, end=" ")
        self.inorder(current.right, False)

    def postorder(self, current = None, is_root = True):
        if current is None and is_root:
            current = self.root

        if current is None:
            return

        self.postorder(current.left, False)
        self.postorder(current.right, False)
        print(current.key, end = " ")

class Node:
    def __init__(self,key = None):
        self.key = key
        self.right = None
        self.left = None

######################################################
# a = Tree()
# x = [int(i) for i in input().split(" ")]
# for i in x:
#     a.insert(i)
# y = a.search(18)
# if y is not None:
#     print("Node 18 exists")
# else:
#     print("Node 18 should be in the Tree")
# z = a.search(5)
# if z is None:
#     print("Node 5 is not present in the Tree")
# else:
#     print("Node 5 should not be in the Tree")
# SAMPLE INPUT
# 10 6 20 8 15 3 18


######################################################
# a = Tree()
# x = [int(i) for i in input().split(" ")]
# for i in x:
#     a.insert(i)
# a.preorder()
# print()
# a.inorder()
# print()
# a.postorder()
# print()

# SAMPLE INPUT
# 30 40 10 9 20 15 25 90 80

# Sample Output:
#
# 30 10 9 20 15 25 40 90 80 
# 9 10 15 20 25 30 40 80 90 
# 9 15 25 20 10 80 90 40 30 
