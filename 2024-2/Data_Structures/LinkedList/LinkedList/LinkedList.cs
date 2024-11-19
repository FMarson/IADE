using System;

namespace LinkedList
{
    public class Node<T>
    {
        public T Data { get; set; }
        public Node<T> Next { get; set; }
        public Node<T> Prev { get; set; }

        public Node(T data)
        {
            Data = data;
            Next = null;
            Prev = null;
        }
    }

    public class DoublyLinkedList<T>
    {
        private Node<T> head;
        private Node<T> tail;

        public DoublyLinkedList()
        {
            head = null;
            tail = null;
        }

        public void AddLast(T data)
        {
            Node<T> newNode = new Node<T>(data);
            if (head == null)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail.Next = newNode;
                newNode.Prev = tail;
                tail = newNode;
            }
        }

        public void AddFirst(T data)
        {
            Node<T> newNode = new Node<T>(data);
            if (head == null)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode.Next = head;
                head.Prev = newNode;
                head = newNode;
            }
        }

        public void Remove(Node<T> node)
        {
            if (node == null) return;

            if (node.Prev != null)
                node.Prev.Next = node.Next;
            else
                head = node.Next;

            if (node.Next != null)
                node.Next.Prev = node.Prev;
            else
                tail = node.Prev;
        }

        public void PrintForward()
        {
            Node<T> current = head;
            while (current != null)
            {
                Console.Write(current.Data + " ");
                current = current.Next;
            }
            Console.WriteLine();
        }

        public void PrintBackward()
        {
            Node<T> current = tail;
            while (current != null)
            {
                Console.Write(current.Data + " ");
                current = current.Prev;
            }
            Console.WriteLine();
        }
        
        public Node<T> Search(T value)
        {
            Node<T> current = head;
            while (current != null)
            {
                if (current.Data.Equals(value))
                {
                    return current;
                }
                current = current.Next;
            }
            
            return null;
        }

        public bool Contains(T value)
        {
            return Search(value) != null; 
        }
        
        protected T PeekFirst()
        {
            if (head == null) throw new InvalidOperationException("List is empty.");
            return head.Data;
        }
        
        protected T PeekLast()
        {
            if (tail == null) throw new InvalidOperationException("List is empty.");
            return tail.Data;
        }
    }
}