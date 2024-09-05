## Concept of Prefix Sum

The main idea behind using prefix sums to solve the "Path Sum III" problem is to keep track of the cumulative sum of values from the root of the tree to the current node. By doing this, you can efficiently check if there is any subpath that sums to the desired val by leveraging previously computed prefix sums.
### Prefix Sum Count Management

1. Tracking Paths to Current Node:
   - When you visit a node, you calculate the currentSum, which is the sum of values from the root to the current node.
   - To determine if there exists a path (from any ancestor to the current node) that sums to the target val, you need to check if the difference between currentSum and the target sum (currentSum - sum) has been encountered before.
2. Updating Prefix Sum Count:
   - Before Recursing (or Pushing Child Nodes): You update the count of the currentSum in the hash map before pushing child nodes to the stack. This is because you need to consider paths that end at the current node. If you do not update the count before visiting child nodes, paths that include the current node and go to its descendants would not be correctly counted.
   - After Recursing: You revert the count of the currentSum after visiting child nodes (i.e., before the next iteration of the loop). This backtracking ensures that paths including the current node are only counted once and that the hash map reflects the correct state for other branches of the tree.

### Example to Illustrate

Consider a simple binary tree:


```
      10
     /  \
    5    -3
   / \     \
  3   2     11
 / \
3  -2
```

And let's say you are looking for paths that sum to 8.

* When visiting the node with val 10:
    - You compute currentSum = 10.
    - You check if (10 - 8) = 2 exists in the hash map. If so, it means there's a path from some ancestor node to the current node that sums to 8.
    - You update the hash map to include currentSum = 10 so that future nodes can consider paths that include this node.

* When visiting node 5:
    - You compute currentSum = 15.
    - You check if (15 - 8) = 7 exists in the hash map.
    - Update the hash map to include currentSum = 15.

* After visiting all descendants of node 10:
    - You revert the count of currentSum = 10 to ensure that other branches of the tree are not incorrectly influenced by the paths including this node.
