//not inplace; you have to create new linkedlist nodes for every tree node
void flatten(node*root,node*dummy,node*itr)
{
    if(dummy->next==nullptr)
    {
        dummy->next=root;
        itr=root;
    }
    else
    {
        itr->next=root;
        itr=itr->next;
    }

    for(int i=0;i<root->child.size();i++)
    {
        flatten(root->child[i],dummy,itr);
    }
    return;
}

node* flattenmain(node*root)
{
    node* dummy=new node(-1);
    node*itr;
    flatten(root,dummy,itr);
    return dummy->next;
}
