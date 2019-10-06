# design_pattern
23种设计模式的C++实现

工厂模式

简单工厂模式，工厂方法模式（抽象工厂模式），
这三种都是解决了一个问题，那就是对象的创建问题。（没看出抽象工厂模式和工厂方法模式有什么大的区别。故不单独列。）
他们的职责就是将对象的创建和对象的使用分离开来。
不同点在于，
- 简单工厂模式，直接把所有产品类的创建逻辑丢到工厂类中，
写起来简单；但是，随着产品量增大，工厂类会变得臃肿，需要解耦。
- 工厂方法模式，只是简单工厂模式的小小改进，定义工厂接口类，
子工厂类继承并实现工厂接口，一类产品对应由一类工厂负责创建。
至少从工厂接口类和产品之间的关系来看，是解耦了。

（探测初始化）

最近工作任务是为新增加的编码硬件（此前已经有一种编码硬件了）编写代码。
如何设计代码，能兼容两种编码卡？
我陷入这个思维中：“上层指定参数，底层根据参数，初始化对应类型的编码卡，
返回句柄；这样子接口需要改，增加类型参数”。
经提示，采用比较技巧性的“探测初始化”，这样就不需要指定编码卡类型了，
接口也就不需要改。

探测初始化，先探测集成显卡，初始化失败的话，则探测新编码卡。
我的理解是，这其实就是工厂模式，只不过生产的产品“异类同质”。
调用者并不需要知道编码卡的类型，只需要一个能提供编码服务的编码器即可。

策略模式

将一组相似的算法，逐一实现为策略类.
- 基于继承的实现：这些策略类继承自同一个接口类，
- 基于函数指针的实现，利用C语言的函数指针或者C++的std::function（->策略抽象），指向具体的函数（->策略）
皆为策略模式。
调用者（环境角色）根据具体的环境实例化策略，获得具体的算法。

适配器模式

名字已经很形象了，这个模式就是将一个接口适配成另一个接口。
就好比，一个三脚插头经过一个适配器就能轻松接上一个二脚插座。
弊端就是，滥用这种模式，容易引起代码混乱，降低可读性。
例如，看到的A接口，穿过适配器这一层，观察其内部可能是一个B接口。

单例模式

单例模式保证一个类仅可以有一个实例化对象，并且提供一个可以访问它的全局接口。
这种模式优点就是节省内存。


原型模式

用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
可以简单理解为克隆。
原型模式的实现，拷贝构造函数是关键。
我的理解是，其实就是拷贝构造函数加了一层壳。
往往应用于这种场景：从头构造一个新的对象比较麻烦，而且已经有现成可以利用的对象。那么实现原型模式之后，
只需要通过clone就能得到一个新的对象（或者对原型对象的引用，这看用途；深浅拷贝皆可，也是从用途出发考虑）

模板模式

我认为，这个模式的实现依赖于“虚函数+继承”。平常用的多，但可能没有从模式上进行过总结。