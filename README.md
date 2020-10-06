# 元胞自动机(C语言)

规则：
- 死亡：当前细胞是生存状态
    - 孤单死亡：相邻8个网格中没有细胞存在
    - 拥挤死亡：相邻8个网格中细胞数大于或等于4
- 复活：相邻8个网格中恰好有3个细胞且当前细胞是死亡状态
- 状态不变：相邻8个网格中恰好有2个细胞

![](https://github.com/ChenYikunReal/c-cellular-automata/blob/master/images/step1.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80Mzg5NjMxOA==,size_16,color_FFFFFF,t_70)

![](https://github.com/ChenYikunReal/c-cellular-automata/blob/master/images/step2.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80Mzg5NjMxOA==,size_16,color_FFFFFF,t_70)

![](https://github.com/ChenYikunReal/c-cellular-automata/blob/master/images/step3.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80Mzg5NjMxOA==,size_16,color_FFFFFF,t_70)

![](https://github.com/ChenYikunReal/c-cellular-automata/blob/master/images/step4.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80Mzg5NjMxOA==,size_16,color_FFFFFF,t_70)

- [特殊符号1](http://www.fhdq.net/)
- [特殊符号2](http://xh.5156edu.com/page/18466.html)
