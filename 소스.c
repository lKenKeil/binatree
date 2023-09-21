#include <stdio.h>
#include <stdlib.h>

// 트리 노드 구조체 정의
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 트리에 노드를 추가하는 함수
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 중위 순회를 반복적으로 수행하는 함수
void iterativeInorder(TreeNode* root) {
    TreeNode* stack[100]; // 스택으로 사용할 배열
    int top = -1; // 스택의 최상위 인덱스

    while (1) {
        while (root) {
            stack[++top] = root;
            root = root->left;
        }

        if (top >= 0) {
            root = stack[top--];
            printf("%d ", root->data);
            root = root->right;
        }
        else {
            break;
        }
    }
}

// 특정 노드의 부모를 찾는 함수
TreeNode* findParent(TreeNode* root, int target) {
    if (root == NULL || (root->left && root->left->data == target) || (root->right && root->right->data == target)) {
        return root;
    }

    TreeNode* leftResult = findParent(root->left, target);
    if (leftResult) {
        return leftResult;
    }

    return findParent(root->right, target);
}

int main() {
    // 이진 트리 생성
    TreeNode n1 = { 4, NULL, NULL };
    TreeNode n2 = { 5, NULL, NULL };
    TreeNode n3 = { 3, &n1, &n2 };
    TreeNode n4 = { 6, NULL, NULL };
    TreeNode n5 = { 2, &n3, &n4 };
    TreeNode n6 = { 10, NULL, NULL };
    TreeNode n7 = { 11, NULL, NULL };
    TreeNode n8 = { 8, NULL, NULL };
    TreeNode n9 = { 9, &n6, &n7 };
    TreeNode n10 = { 7, &n8, &n9 };
    TreeNode n11 = { 1, &n5, &n10 };
    TreeNode* root = &n11;

    // 중위 순회 결과 출력
    printf("중위 순회 결과: ");
    iterativeInorder(root);
    printf("\n");

    // Node 4, Node 5, Node 6의 부모 노드 찾아서 출력
    TreeNode* parent4 = findParent(root, 4);
    TreeNode* parent5 = findParent(root, 5);
    TreeNode* parent6 = findParent(root, 6);

    printf("Node 4의 부모: %d\n", parent4->data);
    printf("Node 5의 부모: %d\n", parent5->data);
    printf("Node 6의 부모: %d\n", parent6->data);

    return 0;
}
