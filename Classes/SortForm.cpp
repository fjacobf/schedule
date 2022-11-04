bool sortStudentByNameAsc(const Student& a1, const Student& a2)
{
    return a1.getname() < a2.getname();
}

bool sortStudentByNameDsc(const Student& a1, const Student& a2)
{
    return a1.getname() > a2.getname();
}

bool sortStudentByCodeAsc(const Student& a1, const Student& a2)
{
    return a1.getcode() < a2.getcode();
}

bool sortStudentByCodeDsc(const Student& a1, const Student& a2)
{
    return a1.getcode() > a2.getcode();
}