def write_add_type(func_name, i):
    add = func_name + '('
    for j in range(0, i):
        add += '*A[%d], ' % j
    add += '\n'
    for j in range(0, i):
        add += 'alpha[%d], ' % j
    add += 'C);'
    print add

for i in range(1, 40):
    print 'case %d:' % (i)
    print 'switch (add_type) {'
    print 'case ADD:'
    write_add_type('Add', i)
    print 'break;'
    print 'case SLOW_ADD:'
    write_add_type('SlowAdd', i)
    print 'break;'
    print 'case DAXPY_ADD:'
    write_add_type('DaxpyAdd', i)
    print 'break;'
    print '}\n'
    print 'break;'

