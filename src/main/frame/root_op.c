#include "frame.h"

double discriminant(double a,double b, double c)
{
	return (b * b - 4 * a * c);
}

t_root roots(double a,double b, double discriminant)
{
	t_root root;
	if(discriminant < 0)
		root.root_number = 0;
	else if (discriminant == 0 )
	{
		root.root_number = 1;
		root.root1 = -b / (-2 * a);
	}
	else
	{
		root.root_number = 2;
		root.root1 = (-b + sqrt(discriminant)) / (-2 * a);
		root.root2 = (-b - sqrt(discriminant)) / (-2 * a);
	}
	return root;
}

void swap_roots(t_root *root)
{
	double temp;
	if(root->root1 < root->root2)
		return ;
	temp = root->root1;
	root->root1 = root->root2;
	root->root2 = temp;
}

t_root root_control(t_root root) // ne döndürsem?
{
	if(root.root_number == 0)
		return root;
	else if (root.root1 < 0 || root.root2 < 0)
	{
		root.root_number = 0;
	}
	swap_roots(&root);
	return root;
}