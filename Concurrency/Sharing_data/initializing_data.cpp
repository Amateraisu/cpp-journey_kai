// suitable for database usages



std::shared_ptr<some_resource> resource_ptr;

void foo() {
    if (!resource_ptr) {
        resource_ptr.reset(new some_resource);
    }
    resource_ptr->do_something();
}
