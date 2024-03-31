#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>

/******************************** Tree Stack ********************************/
struct TreeNode
{
    char data;
    struct TreeNode *left, *right;
};

struct TreeStackNode {
    struct TreeNode* data;
    struct TreeStackNode *next, *previous;
};

struct TreeStack {
    int size;
    struct TreeStackNode *top;
} *treeStack;

struct TreeStackNode* popTreeNode(){
    if (treeStack->size == 0)
        return NULL;
    treeStack->size--;
    struct TreeStackNode* top = treeStack->top;
    treeStack->top = top->previous;
    return top;
}

void pushTreeNode(struct TreeNode* data) {
    struct TreeStackNode* new = (struct TreeStackNode*) malloc(sizeof (struct TreeStackNode));
    new->data = data;
    new->next = new->previous = NULL;
    treeStack->size++;
    if (treeStack->size == 1) {
        treeStack->top = new;
        return;
    }
    struct TreeStackNode* top = treeStack->top;
    treeStack->top->next = new;
    treeStack->top = new;
    treeStack->top->previous = top;
}

/******************************** Character Stack ********************************/
struct CharStackNode {
    char data;
    struct CharStackNode *next, *previous;
};

struct CharStack {
    struct CharStackNode *top;
    int size;
} *charStack;

struct CharStackNode* popChar() {
    if (charStack->size == 0)
        return NULL;
    charStack->size--;
    struct CharStackNode* top = charStack->top;
    charStack->top = top->previous;
    return top;
}

void pushChar(char data) {
    struct CharStackNode* new = (struct CharStackNode*) malloc(sizeof (struct CharStackNode));
    new->data = data;
    new->next = new->previous  = NULL;
    charStack->size++;
  
    if(charStack->size == 1) {
        charStack->top = new;
        return;
    }
  
    struct CharStackNode* top = charStack->top;
    charStack->top->next = new;
    charStack->top = new;
    charStack->top->previous = top;
}

struct CharStackNode* peekChar() {
    return charStack->top;
}

int isCharStackEmpty() {
    return charStack->size == 0;
}

/******************************** Tree Construction ********************************/
int isOperand(char ch) {
    char flag =0;
    if ((ch >= '0' && ch <= '9')||(ch >= 0 && ch <= 9))flag =1;
    return flag;
}
int isNotOperand(char ch) {
    char flag =1;
    if ((ch =='+' || ch =='-'|| ch =='*'|| ch =='/'||ch =='%'||ch =='^'))flag =0;
    return flag;
}

int getPrecedence(char operation) {
    char precedence_num=-1;
    switch (operation) {
    case '+':
    case '-':
        precedence_num = 1;
        break;
    case '*':
    case '/':
    case '%':
        precedence_num =  2;
        break;
    case '^':
        precedence_num =  3;
        break;
    }
    return precedence_num;
}

struct TreeNode* newTreeNode(char data) {
    struct TreeNode* treeNode = (struct TreeNode*) malloc(sizeof (struct TreeNode));
    treeNode->data= data;
    treeNode->left = treeNode->right = NULL;
    return treeNode;
}

void constructOperationNode() {
    struct TreeNode* node = newTreeNode(popChar()->data);
    struct TreeStackNode* right = popTreeNode();
    struct TreeStackNode* left = popTreeNode();

    node->left = left->data;
    node->right = right->data;
    pushTreeNode(node);
}
struct TreeNode* constructTree(char* expression) {
    int i = 0;
    while (expression[i] != '\0') {
        if (isOperand(expression[i])) {
            int operand = 0;
            while (isOperand(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Move back one position to correctly handle the next character
            pushTreeNode(newTreeNode(operand )); // Convert integer back to char and push to stack
        }
        else if (expression[i] == '(') {
            pushChar(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!isCharStackEmpty() && peekChar()->data != '(' && treeStack->size > 1) {
                constructOperationNode();
            }
            popChar();
        }
        else if (getPrecedence(expression[i])) {
            while (!isCharStackEmpty() && peekChar()->data != '(' && treeStack->size > 1 &&
                   getPrecedence(expression[i]) <= getPrecedence(peekChar()->data)) {
                constructOperationNode();
            }
            pushChar(expression[i]);
        }
        i++;
    }
    return popTreeNode()->data;
}


// void printPostorder(struct TreeNode* node) {
//     if(node == NULL)
//         return;
//     printPostorder(node->left);
//     printPostorder(node->right);
//     printf("%c", node->data);
// }
int performOperation(int a, int b, char operation) {
    switch (operation) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return a % b;
        case '^':
            return (int)pow(a, b);
    }
    return 0;
}

 int evaluateExpressionTree(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (isNotOperand(root->data)) {
        return root->data ; // Convert char to integer
    }
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);
    return performOperation(leftValue, rightValue, root->data);
}


/******************************** Main ********************************/
int main()
{
    char expression[10002];
    scanf("%s", expression);

   int i = 0;
    while (expression[i] != '\0') {

        if (expression[i] == '*' && expression[i + 1] == '*') {
        
            expression[i] = '^';
            // Shifting remaining characters to replace the '**'
            int j;
            for (j = i + 1; expression[j] != '\0'; j++) {
                expression[j] = expression[j + 1];
            }
        }
        i++;
    }

    
    // Initialize stacks
    treeStack = (struct TreeStack*) malloc(sizeof (struct TreeStack));
    treeStack->size = 0;
    charStack = (struct CharStack*) malloc(sizeof (struct CharStack));
    charStack->size = 0;
    
    // Add parenthesis to the expression
    strcat(expression, ")");
    pushChar('(');
    // Construct expression tree
    struct TreeNode* root = constructTree(expression);
  //  printPostorder(root);

    // Evaluate expression tree
    int result = evaluateExpressionTree(root);
    printf("Result: %d\n", result);

    return 0;
}