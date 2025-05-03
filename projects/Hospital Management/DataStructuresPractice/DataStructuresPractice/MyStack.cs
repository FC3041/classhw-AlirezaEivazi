using System;

class MyStack<T>
{
    List<T> _Items = new List<T>();

    public void Push(T Item)
    {
        _Items.Add(Item);
    }
    public T Pop()
    {
        if(_Items.Count == 0)
        {
            throw new InvalidOperationException("nothing item found!");
        }
        T LastItem = _Items[_Items.Count - 1];
        _Items.RemoveAt(_Items.Count - 1);
        return LastItem;
    }
    public T Peek()
    {
        if (_Items.Count == 0)
            throw new InvalidOperationException("Stack is empty!");

        return _Items[_Items.Count - 1];
    }

    public int Count
    {
        get { return _Items.Count; }
    }
    public void Print()
    {
        for (int i = _Items.Count - 1; i >= 0; i--)
        {
            Console.WriteLine(_Items[i]);
        }
    }

}

class MyQueue<T>
{
    List<T>_ITems = new List<T>();

    public void EnQueue(T Item)
    {
        _ITems.Add(Item);
    }
    public T DeQueue()
    {
        if (_ITems.Count == 0)
        {
            throw new InvalidOperationException("Queue is empty");
        }
        T FirstItem = _ITems[0];
        _ITems.RemoveAt(0);
        return FirstItem;

    }
    public T Peek()
    {
        if (_ITems.Count == 0)
        {
            throw new InvalidOperationException("Queue is empty");
        }
        T FirstItem = _ITems[0];
        return FirstItem;
    }

    public int Count
    {
        get { return _ITems.Count; }
    }

    public void Print()
    {
       for (int i = 0; i < _ITems.Count; i++)
        {
            Console.WriteLine(_ITems[i]);
        }

    }
}