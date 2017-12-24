class Node(object):
    def __init__(self):
        self.children  = [None]*26
        self.value = 0
 
    def leafNode(self):
        return self.value != 0
 
    def isItFreeNode(self):
        for c in self.children:
            if c:return False
        return True
 
 
class Trie(object):
    def __init__(self):
        self.root = Node()
        self.count = 0;
 
    def _Index(self,ch):
        return ord(ch.lower())-ord('a')

    def insert(self,key):
        length = len(key)
        pCrawl = self.root
        self.count += 1
        for level in range(length):
            index = self._Index(key[level])
            if pCrawl.children[index]:
                pCrawl = pCrawl.children[index]
            else:
                pCrawl.children[index] = Node()
                pCrawl = pCrawl.children[index]
        pCrawl.value = self.count
 
    def search(self, key):
        length = len(key)
        pCrawl = self.root
        for level in range(length):
            index = self._Index(key[level])
            if not pCrawl.children[index]:
                return False
            pCrawl = pCrawl.children[index]
 
        return pCrawl != None and pCrawl.value != 0
 
 
    def delete(self,pNode,key,level,length):
        if pNode:
            if level == length:
                if pNode.value:
                    pNode.value = 0
                return pNode.isItFreeNode()
            else:
                index = self._Index(key[level])
                if self.delete(pNode.children[index],key,level+1,length):
                    pNode.children[index] = None
                    return (not pNode.leafNode() and pNode.isItFreeNode())
 
        return False

    def updateKey(self,key1,key2):
        self.insert(key2)
        length = len(key1)
        if length > 0:
            self.delete(self.root,key1,0,length)

trie = Trie()
trie.insert("sachin")
print("sachin "+("Found" if trie.search("sachin") else "Not Found"))
trie.updateKey("sachin","sam")
print("sachin "+("Found" if trie.search("sachin") else "Not Found"))
print("sam "+("Found" if trie.search("sam") else "Not Found"))