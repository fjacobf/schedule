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

bool sortClassByCodeAsc(const Class& a1, const Class& a2)
{
    return a1.getClassCode() > a2.getClassCode();
}

bool sortClassByCodeDsc(const Class& a1, const Class& a2)
{
    return a1.getClassCode() < a2.getClassCode();
}

bool sortClassByUcCodeAsc(const Class& a1, const Class& a2)
{
    return a1.getUcCode() > a2.getUcCode();
}

bool sortClassByUcCodeDsc(const Class& a1, const Class& a2)
{
    return a1.getUcCode() < a2.getUcCode();
}

bool sortClassByCapacityAsc(const Class& a1, const Class& a2)
{
    return a1.getCapacity() > a2.getCapacity();
}

bool sortClassByCapacityDsc(const Class& a1, const Class& a2)
{
    return a1.getCapacity() < a2.getCapacity();
}

bool sortUcByUcCodeAsc(const Uc& a1, const Uc& a2)
{
    return a1.getUcCode() > a2.getUcCode();
}

bool sortUcByUcCodeDsc(const Uc& a1, const Uc& a2)
{
    return a1.getUcCode() < a2.getUcCode();
}

bool sortTime_SlotByStarHourAsc(const Time_slot& a1, const Time_slot& a2)
{
    return a1.getstarthour() > a2.getstarthour();
}

bool sortTime_SlotByStarHourDsc(const Time_slot& a1, const Time_slot& a2)
{
    return a1.getstarthour() < a2.getstarthour();
}

bool sortTime_SlotByDurationAsc(const Time_slot& a1, const Time_slot& a2)
{
    return a1.getduration() > a2.getduration();
}

bool sortTime_SlotByDurationDsc(const Time_slot& a1, const Time_slot& a2)
{
    return a1.getduration() < a2.getduration();
}