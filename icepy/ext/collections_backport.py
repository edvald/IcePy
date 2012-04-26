class OrderedDict(dict):
    # Methods with direct access to underlying attributes

    def __init__(self, *args, **kwds):
        if len(args) > 1:
            raise TypeError('expected at 1 argument, got %d', len(args))
        if not hasattr(self, '_keys'):
            self._keys = []
        self.update(*args, **kwds)

    __marker = object()

    def clear(self):
        del self._keys[:]
        dict.clear(self)

    def __setitem__(self, key, value):
        if key not in self:
            self._keys.append(key)
        dict.__setitem__(self, key, value)

    def __delitem__(self, key):
        dict.__delitem__(self, key)
        self._keys.remove(key)

    def __iter__(self):
        return iter(self._keys)

    def __reversed__(self):
        return reversed(self._keys)

    def popitem(self):
        if not self:
            raise KeyError
        key = self._keys.pop()
        value = dict.pop(self, key)
        return key, value

    def __reduce__(self):
        items = [[k, self[k]] for k in self]
        inst_dict = vars(self).copy()
        inst_dict.pop('_keys', None)
        return (self.__class__, (items,), inst_dict)

    # Methods with indirect access via the above methods
    def pop(self, key, default=__marker):
        try:
            value = self[key]
        except KeyError:
            if default is self.__marker:
                raise
            return default
        else:
            del self[key]
            return value

    def update(self, other=(), **kwds):
        if isinstance(other, (dict,OrderedDict)):
            for key in other:
                self[key] = other[key]
        elif hasattr(other, "keys"):
            for key in other.keys():
                self[key] = other[key]
        else:
            for key, value in other:
                self[key] = value
        for key, value in kwds.items():
            self[key] = value

    def setdefault(self, key, default=None):
        try:
            return self[key]
        except KeyError:
            self[key] = default
        return default

    def get(self, key, default=None):
        try:
            return self[key]
        except KeyError:
            return default

    def __contains__(self, key):
        try:
            self[key]
        except KeyError:
            return False
        else:
            return True

    def iterkeys(self):
        return iter(self)

    def itervalues(self):
        for key in self:
            yield self[key]

    def iteritems(self):
        for key in self:
            yield (key, self[key])

    def keys(self):
        return list(self)

    def items(self):
        return [(key, self[key]) for key in self]

    def values(self):
        return [self[key] for key in self]

    # Mappings are not hashable by default, but subclasses can change this
    __hash__ = None

    def __eq__(self, other):
        return isinstance(other, (dict,OrderedDict)) and \
               dict(self.items()) == dict(other.items())

    def __ne__(self, other):
        return not (self == other)

    def __repr__(self):
        pairs = ', '.join(map('%r: %r'.__mod__, self.items()))
        return '%s({%s})' % (self.__class__.__name__, pairs)

    def copy(self):
        return self.__class__(self)

    @classmethod
    def fromkeys(cls, iterable, value=None):
        d = cls()
        for key in iterable:
            d[key] = value
        return d

class FrozenDict(OrderedDict):
    def __init__(self, odict):
        if not hasattr(self, '_keys'):
            self._keys = []
        if isinstance(odict, (list,tuple)):
            for item in odict:
                if not isinstance(item, (list,tuple)) or len(item)!=2:
                    raise ValueError('Unsupported initializing argument')
                key, val = item
                self._keys.append(key)
                dict.__setitem__(self, key, val)
        else:
            if not isinstance(odict, (FrozenDict,OrderedDict)):
                print odict
                raise ValueError('Unsupported')

            for key in odict:
                self._keys.append(key)
                dict.__setitem__(self, key, odict[key])
        
        self._keys = tuple(self._keys)

    __marker = object()

    def clear(self):
        raise NotImplementedError

    def __setitem__(self, key, value):
        raise NotImplementedError

    def __delitem__(self, key):
        raise NotImplementedError

    def __hash__(self):
        return hash(self.items())

    def popitem(self):
        raise NotImplementedError

    # Methods with indirect access via the above methods
    def pop(self, key, default=__marker):
        raise NotImplementedError

    def update(self, other=(), **kwds):
        raise NotImplementedError

    def setdefault(self, key, default=None):
        raise NotImplementedError

    def keys(self):
        return self._keys

    def items(self):
        return tuple([(key, self[key]) for key in self])

    def values(self):
        return tuple([self[key] for key in self])

    @classmethod
    def fromkeys(cls, iterable, value=None):
        o = OrderedDict.fromkeys(iterable, value)
        d = cls(o)
        return d

if __name__=="__main__":
    from time import time

    odict  = OrderedDict([['', ('nven', 'nveo', 'nve<')], ['a', ('nvfe',)], ['anna', ('nvfeg',)], ['ar', ('nvee',)], ['arinnar', ('nveeg',)], ['in', ('nveng',)], ['ina', ('nveog',)], ['inni', ('nve<g',)], ['ir', ('nvfn', 'nvfo')], ['irnar', ('nvfng', 'nvfog')], ['um', ('nvf<',)], ['unum', ('nvf<g',)]])
    frozen = FrozenDict(odict)
    d = dict([['', ('nven', 'nveo', 'nve<')], ['a', ('nvfe',)], ['anna', ('nvfeg',)], ['ar', ('nvee',)], ['arinnar', ('nveeg',)], ['in', ('nveng',)], ['ina', ('nveog',)], ['inni', ('nve<g',)], ['ir', ('nvfn', 'nvfo')], ['irnar', ('nvfng', 'nvfog')], ['um', ('nvf<',)], ['unum', ('nvf<g',)]])

    print frozen
    print d

    t0 = time()
    for i in range(1000000):
        a = frozen['arinnar']
    print time()-t0

    t0 = time()
    for i in range(1000000):
        a = d['arinnar']
    print time()-t0