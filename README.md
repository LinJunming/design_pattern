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

建造者模式

零件的生产各异，但是组装的程序基本相同。
建造者模式下，以手机为例：
组装程序被抽象出来，体现为一个Director，是基本不变的；
而不同产品的零件生产方式和原材料是不同的，这部分抽出来作为Builder；
产品的零件种类是基本相同的，体现为一个Phone.
建造者模式带来的便利是，新增产品只需要新增各个零件的制造方法（Builder）即可，不需要重复编写组装程序。
建造者对不同产品之间的一致性要求比较苛刻。
工厂大批量生产的产品，比如手机，就符合要求，不同厂家的手机，零件类型基本一样，装配顺序也差不多。
没有大规模生产的产品，比如肠粉，就不符合要求，早茶肠粉，切成小卷；潮式肠粉，皮包肉；上班族肠粉，皮带肉——装配顺序都不一样。

外观模式

现实世界充满了这种模式，一个被市场广为接受的好产品，肯定有一个对用户友好的外观。
电脑的开机过程，包括了CPU上电，系统引导，外设加载，但是暴露给用户的就是一个简单的按钮；
请求一个网页，包括了请求数据的封装，发送，接受返回数据，解析，呈现到页面上，但是暴露给用户的只是一个网页按钮。

组合模式

和外观模式有点像，封装了很多子对象。
但是组合模式和外观模式强调的不一样：
外观模式强调的是“隐藏复杂的内部过程和细节，对外提供友好的操作接口”，
组合模式强调的是“管理根对象（整体）和子对象（部分）的关系，对外表现为一个有组织的整体”。

代理模式

本来简简单单、直截了当的，这下多一个代理，如果还只是简单地把交代的事情办了，那就没意义了。
肯定不是把交代的事情办了这么简单，代理模式可以做很多其他的事情。
多一个代理，那么这个代理就可以加入“权限控制”，“安全管理”，“远程代表”，“虚拟代理”等等。
举例子，
- 游戏权限代理（不同级别的代理，有不同级别的权限）；
- 智能指针（把指针内存管理的摊子接管了）；
- 大使馆（两国大部分的沟通是通过外交官来做）；
- CDN（各地CDN，缓存，就是代理，应付大部分的请求）；
- 延迟加载/创建/写，这就是虚拟代理，其意义在于“优化”。
比如大型文档的加载，肯定不需要一下子把所有内容都读进来。
实现一个代理，每次翻页再做加载，这样文件打开速度不慢，浏览也不会卡顿；
- 律师（代理客户的诉讼请求，为之做出专业的陈诉甚至争取利益）
代理模式又被誉为“万能的中间层”。

装饰者模式

用一堆装饰器给被装饰者增加功能/任务。

观察者模式

被观察者管理一堆观察者，并定义 Notify接口，用于逐个调用观察者的update接口，实现事件通知。
观察者依赖与被观察者（引用其指针），并在Update的时候，通过该指针获取相关信息。

命令模式

“下命令的对象 - 命令 - 命令执行人”
下命令的对象维护着命令列表，并通过notify接口下达命令。
每个命令的子类维护着对应的命令执行人，
命令执行人实际执行命令。
下命令的对象和命令执行人直接实现解耦。