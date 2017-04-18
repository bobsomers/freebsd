#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>

static int event_handler(struct module* module, int event, void* arg) {
  int e = 0;

  switch (event) {
  case MOD_LOAD:
    uprintf("PikuSomers File System is da best!\n");
    break;

  case MOD_UNLOAD:
    uprintf("PikuSomers File System is too cool for you!\n");
    break;

  default:
    e = EOPNOTSUPP;
    break;
  }

  return e;
}

static moduledata_t pikusomers_conf = {
  "pikusomersfs",
  event_handler,
  NULL,
};

DECLARE_MODULE(pikusomersfs, pikusomers_conf, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);
