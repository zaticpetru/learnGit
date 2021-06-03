import sys

def swap(n1, n2):
    n1.key, n2.key = n2.key, n1.key


class Tree:

    def __init__(self, root = None):
        self.root = root

    def insert(self, val, current = None):
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
        
    def min_value_node(self, node):
        current = node
        while(current.left is not None):
            current = current.left
        return current;
    
    def delete_node(self, key, root = None, start_from_root = True):
        if start_from_root is True:
            root = self.root
        if root is None:
            return

        if key < root.key:
            root.left = self.delete_node(key, root = root.left, start_from_root = False)
        elif (key > root.key):
            root.right = self.delete_node(key, root = root.right, start_from_root = False)
        else:

            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp

            temp = self.min_value_node(root.right)

            root.key = temp.key

            root.right = self.delete_node(temp.key, root = root.right, start_from_root = False)
        return root
    
    def mirror_tree(self, node = None, is_root = True):
        if node is None and is_root is True:
            node = self.root

        if node is None:
            return

        if node.left is not None:
            self.mirror_tree(node.left, is_root = False)

        if node.right is not None:
            self.mirror_tree(node.right, is_root = False)

        node.left, node.right = node.right, node.left

    def is_binary_search_tree(self, node, minKey, maxKey):
        if node is None:
            return True
        if node.key < minKey or node.key > maxKey:
            return False
        return self.is_binary_search_tree(node.left, minKey, node.key) and self.is_binary_search_tree(node.right, node.key, maxKey)
    
    def check_tree(self):
        if self.is_binary_search_tree(self.root, -sys.maxsize, sys.maxsize):
            print("DA")
        else:
            print("NU")

    def print_tree(self):
        nodes = []
        if self.root != None:
            nodes.append(self.root)
        while len(nodes) != 0:
            el = nodes.pop(0)
            if el.left != None:
                nodes.append(el.left)
            if el.right != None:
                nodes.append(el.right)
            print(el.key,end=' ')


class Node:
    def __init__(self, key = None):
        self.key = key
        self.right = None
        self.left = None

######################################################
# a = Tree()
# x = [int(i) for i in input().split(" ")]
# for i in x:
#     a.insert(i)
    
# a.delete_node(9)
# a.delete_node(5)
# a.delete_node(18)
# a.preorder()

# Sample Input:
# 12 5 9 18 15 2 19 13 17

# Sample Output:
# 12 2 19 15 13 17

######################################################
# a = Tree()
# x = [int(i) for i in input().split(" ")]
# for i in x:
#     a.insert(i)

# a.mirror_tree()
# a.preorder()

# Sample Input:
# 5 10 4 3 12

# Sample Output:
# 5 10 12 4 3


######################################################
# a = Tree()
# x = [int(i) for i in input().split(" ")]
# for i in x:
#     a.insert(i)
# swap(a.root.left, a.root.right)  
# a.check_tree()


# Sample Input:
# 6 3 7 1 9 10

# Sample Output:
# NU


######################################################

# a = Tree()
# x = [int(i) for i in input().split(" ")]
# for i in x:
#     a.insert(i)
    
# a.print_tree()

# Sample Input:
# 12 5 18 2 9 15 19 13 17

# Sample Output:
# 12 5 18 2 9 15 19 13 17
