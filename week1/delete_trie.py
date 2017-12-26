
class TrieNode(object):
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
        self.root = self.getNode()
        self.count = 0;
 
    def _Index(self,ch):
        return ord(ch)-ord('a')
 
    def getNode(self):
        return TrieNode()
 
    def insert(self,key):
        length = len(key)
        pCrawl = self.root
        self.count += 1
 
        for level in range(length):
            index = self._Index(key[level])
 
            if pCrawl.children[index]:
                pCrawl = pCrawl.children[index]
            else:
                pCrawl.children[index] = self.getNode()
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
 
 
    def _deleteHelper(self,pNode,key,level,length):
        if pNode:
            if level == length:
                if pNode.value:
                    pNode.value = 0
                return pNode.isItFreeNode()
 
        else:
                index = self._Index(key[level])
        if self._deleteHelper(pNode.children[index],\
                key,level+1,length):
            del pNode.children[index]
            return (not pNode.leafNode() and \
                    pNode.isItFreeNode())
        return False
 
    def deleteKey(self,key):
        length = len(key)
        if length > 0:
            self._deleteHelper(self.root,key,0,length)  
 
 
def main():
    keys = ["Raju","loves","kurkure","lays","doritos","sandwiches","pastries"]
    trie = Trie()
    for key in keys:
        trie.insert(key)
 
    trie.deleteKey(keys[0])
 
    print("{} {}".format(keys[0],\
        "Present in trie" if trie.search(keys[0]) \
                        else "Not present in trie"))
 
    print("{} {}".format(keys[6],\
        "Present in trie" if trie.search(keys[6]) \
                        else "Not present in trie"))    
 
if __name__ == '__main__':
    main()
