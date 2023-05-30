/** added by Yangfan */
void Net::disconnectNonIOPins()
{
    ArrayObject<ObjectId>* pin_vector = nullptr; // new pin vector
    ArrayObject<ObjectId> *vct = getPinArray();
    uint64_t pin_nums = vct->getSize();
    ObjectId pins = __createObjectIdArray(pin_nums);

    pin_vector = addr<ArrayObject<ObjectId>>(pins);
    int i;
    for(i = 0; i < pin_nums; i++)
    {
        ObjectId pin_id = (*vct)[i];
        Pin* p = addr<Pin>(pin_id);
        if(p->getIsIOPin())
        {
            pin_vector->pushBack(p->getId());
        }
        else
        {
            Net * nptr = nullptr;
            p->setNet(nptr);
        }
    }
    __destroyObjectIdArray(pins_);
    pins_ = pins;
}

/** added end */
