#include <stdio.h>
#include <stdlib.h>

// Ʈ�� ��� ����ü ����
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Ʈ���� ��带 �߰��ϴ� �Լ�
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ���� ��ȸ�� �ݺ������� �����ϴ� �Լ�
void iterativeInorder(TreeNode* root) {
    TreeNode* stack[100]; // �������� ����� �迭
    int top = -1; // ������ �ֻ��� �ε���

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

// Ư�� ����� �θ� ã�� �Լ�
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
    // ���� Ʈ�� ����
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

    // ���� ��ȸ ��� ���
    printf("���� ��ȸ ���: ");
    iterativeInorder(root);
    printf("\n");

    // Node 4, Node 5, Node 6�� �θ� ��� ã�Ƽ� ���
    TreeNode* parent4 = findParent(root, 4);
    TreeNode* parent5 = findParent(root, 5);
    TreeNode* parent6 = findParent(root, 6);

    printf("Node 4�� �θ�: %d\n", parent4->data);
    printf("Node 5�� �θ�: %d\n", parent5->data);
    printf("Node 6�� �θ�: %d\n", parent6->data);

    return 0;
}
