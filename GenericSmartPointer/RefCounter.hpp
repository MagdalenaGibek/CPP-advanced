#pragma once
class RefCounter
{
private:
    int count; // Reference count

public:
    void AddRef()
    {
        // Increment the reference count
        count++;
    }

    int getCount() const
    {
        return count;
    }

    int Release()
    {
        // Decrement the reference count and
        // return the reference count.
        return --count;
    }
};
