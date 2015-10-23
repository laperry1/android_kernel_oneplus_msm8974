#ifndef __LINUX_VMPRESSURE_H
#define __LINUX_VMPRESSURE_H

#include <linux/mutex.h>
#include <linux/list.h>
#include <linux/workqueue.h>
#include <linux/gfp.h>
#include <linux/types.h>
#include <linux/cgroup.h>

struct vmpressure {
	unsigned long scanned;
	unsigned long reclaimed;
<<<<<<< HEAD
=======
	unsigned long stall;
>>>>>>> 06b8e73d2a5a72319192223b85db4543f75fb1bd
	/* The lock is used to keep the scanned/reclaimed above in sync. */
	struct mutex sr_lock;

	/* The list of vmpressure_event structs. */
	struct list_head events;
	/* Have to grab the lock on events traversal or modifications. */
	struct mutex events_lock;

	struct work_struct work;
};

struct mem_cgroup;

<<<<<<< HEAD
#ifdef CONFIG_CGROUP_MEM_RES_CTLR
=======
extern int vmpressure_notifier_register(struct notifier_block *nb);
extern int vmpressure_notifier_unregister(struct notifier_block *nb);
>>>>>>> 06b8e73d2a5a72319192223b85db4543f75fb1bd
extern void vmpressure(gfp_t gfp, struct mem_cgroup *memcg,
		       unsigned long scanned, unsigned long reclaimed);
extern void vmpressure_prio(gfp_t gfp, struct mem_cgroup *memcg, int prio);

<<<<<<< HEAD
=======
#ifdef CONFIG_CGROUP_MEM_RES_CTLR
>>>>>>> 06b8e73d2a5a72319192223b85db4543f75fb1bd
extern void vmpressure_init(struct vmpressure *vmpr);
extern struct vmpressure *memcg_to_vmpressure(struct mem_cgroup *memcg);
extern struct cgroup_subsys_state *vmpressure_to_css(struct vmpressure *vmpr);
extern struct vmpressure *css_to_vmpressure(struct cgroup_subsys_state *css);
extern int vmpressure_register_event(struct cgroup *cg, struct cftype *cft,
				     struct eventfd_ctx *eventfd,
				     const char *args);
extern void vmpressure_unregister_event(struct cgroup *cg, struct cftype *cft,
					struct eventfd_ctx *eventfd);
#else
<<<<<<< HEAD
static inline void vmpressure(gfp_t gfp, struct mem_cgroup *memcg,
			      unsigned long scanned, unsigned long reclaimed) {}
static inline void vmpressure_prio(gfp_t gfp, struct mem_cgroup *memcg,
				   int prio) {}
=======
static inline struct vmpressure *memcg_to_vmpressure(struct mem_cgroup *memcg)
{
	return NULL;
}
>>>>>>> 06b8e73d2a5a72319192223b85db4543f75fb1bd
#endif /* CONFIG_CGROUP_MEM_RES_CTLR */
#endif /* __LINUX_VMPRESSURE_H */
