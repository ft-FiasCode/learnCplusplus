struct arrayStack{
	int top;
	int capacity;
	int *array;
	 
};

struct arrayStack* createStack(int cap)
{
	struct arrayStack *stack;
	stack= malloc(sizeof(struct arrayStac));
	
	stack->capacity=cap;
	stack->top=-1;
	stack->array=malloc(sizeof(int)*capacity);
	return (stack);
		
}
void push(struct arrayStack *stack,int item)
{
	if(!isFull(stack))
	{
		item=stack->array[top]
		stack->top--;
		printf"&dstack is full",item;
	}
	
}

void pop(struct arrayStack *stack,int item)
{
	if(!isFull(stack))
	{
		int item;
		stack->top++;
		stack->array[top]=item;
	}
	
}
void isFull(struct arrayStack *stack)
{
	if(stack->top==stack->capacity-1)
	printf"stack is full";
}
